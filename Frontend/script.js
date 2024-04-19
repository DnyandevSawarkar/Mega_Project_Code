document.addEventListener("DOMContentLoaded", function() {
    var blocks = document.querySelectorAll(".block");

    // Enable drag-and-drop for blocks within the workspace
    blocks.forEach(function(block) {
        var select = block.querySelector(".number-select");
        if (select) {
            for (var i = 1; i <= 1000; i++) {
                var option = document.createElement("option");
                option.text = i;
                option.value = i;
                select.appendChild(option);
            }
        }
        block.draggable = true;
        block.addEventListener("dragstart", function(event) {
            event.dataTransfer.setData("text/plain", event.target.id);
        });
    });

    var workspace = document.getElementById("workspace");

    // Allow drop on workspace
    workspace.addEventListener("dragover", function(event) {
        event.preventDefault();
        var targetBlock = event.target.closest(".block");
        if (targetBlock) {
            targetBlock.classList.add("dragging-over");
        }
    });

    // Handle drag leave event
    workspace.addEventListener("dragleave", function(event) {
        var targetBlock = event.target.closest(".block");
        if (targetBlock) {
            targetBlock.classList.remove("dragging-over");
        }
    });

    // Handle drop event on workspace
    workspace.addEventListener("drop", function(event) {
        event.preventDefault();

        var data = event.dataTransfer.getData("text/plain");
        var draggedBlock = document.getElementById(data);
        var targetBlock = event.target.closest(".block");

        if (draggedBlock.closest(".control-container")) {
            // Clone the dragged block before appending it to the workspace
            var clonedBlock = draggedBlock.cloneNode(true);
            // Enable drag-and-drop for the cloned block
            clonedBlock.draggable = true;

            // Add delete icon to cloned block
            var deleteIcon = document.createElement("i");
            deleteIcon.classList.add("fas", "fa-times", "delete-block");
            clonedBlock.prepend(deleteIcon);

            // Insert the cloned block into the workspace at the correct position
            if (targetBlock && draggedBlock !== targetBlock) {
                if (event.clientY < targetBlock.getBoundingClientRect().top + targetBlock.offsetHeight / 2) {
                    workspace.insertBefore(clonedBlock, targetBlock); // Move cloned block before the target block
                } else {
                    workspace.insertBefore(clonedBlock, targetBlock.nextElementSibling); // Move cloned block after the target block
                }
            } else {
                workspace.appendChild(clonedBlock); // If dropped outside any block, append to the end of workspace
            }

            // Delete block when delete icon is clicked
            deleteIcon.addEventListener("click", function() {
                clonedBlock.remove();
            });
        } else {
           // Reorder blocks within the workspace
           if (targetBlock && draggedBlock !== targetBlock) {
                if (event.clientY < targetBlock.getBoundingClientRect().top + targetBlock.offsetHeight / 2) {
                    workspace.insertBefore(draggedBlock, targetBlock); // Move dragged block before the target block
                } else {
                    workspace.insertBefore(draggedBlock, targetBlock.nextElementSibling); // Move dragged block after the target block
                }
            } else {
                workspace.appendChild(draggedBlock); // If dropped outside any block, append to the end of workspace
            }
        }

        // Remove dragging-over class from all blocks
        var allBlocks = document.querySelectorAll(".block");
        allBlocks.forEach(function(block) {
            block.classList.remove("dragging-over");
        });
    });

    // Save workspace data to text file
   // Save workspace data to text file
    var submitButton = document.getElementById("submitButton");

    submitButton.addEventListener("click", function() {
    var workspaceBlocks = document.querySelectorAll(".workspace .block");
    var blockData = "";

    workspaceBlocks.forEach(function(block) {
        var blockName = block.textContent.trim().split(':')[0].trim();
        var blockValue = parseInt(block.querySelector(".number-select").value);
        for (var i = 0; i < blockValue; i++) {
            blockData += blockName + "\n";
        }
    });

    // Send block data to the backend server on port 5000
    fetch('http://127.0.0.1:5000/submit', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
        },
        body: 'block_data=' + encodeURIComponent(blockData),
    }).then(response => {
        if (response.ok) {
            console.log('Data saved successfully!');
        } else {
            console.error('Failed to save data:', response.statusText);
        }
    }).catch(error => {
        console.error('Error saving data:', error);
    });
});

});