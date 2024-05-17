document.addEventListener("DOMContentLoaded", function() {
    var blocks = document.querySelectorAll(".block");
    blocks.forEach(function(block) {
        var select = block.querySelector(".number-select");
        if (select) {
            for (var i = 1; i <= 150; i++) {
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
    workspace.addEventListener("dragover", function(event) {
        event.preventDefault();
        var targetBlock = event.target.closest(".block");
        if (targetBlock) {
            targetBlock.classList.add("dragging-over");
        }
    });

    workspace.addEventListener("dragleave", function(event) {
        var targetBlock = event.target.closest(".block");
        if (targetBlock) {
            targetBlock.classList.remove("dragging-over");
        }
    });

    workspace.addEventListener("drop", function(event) {
        event.preventDefault();

        var data = event.dataTransfer.getData("text/plain");
        var draggedBlock = document.getElementById(data);
        var targetBlock = event.target.closest(".block");

        if (draggedBlock.closest(".control-container")) {
            var clonedBlock = draggedBlock.cloneNode(true);
            clonedBlock.draggable = true;

            var deleteIcon = document.createElement("i");
            deleteIcon.classList.add("fas", "fa-times", "delete-block");
            clonedBlock.prepend(deleteIcon);

            if (targetBlock && draggedBlock !== targetBlock) {
                if (event.clientY < targetBlock.getBoundingClientRect().top + targetBlock.offsetHeight / 2) {
                    workspace.insertBefore(clonedBlock, targetBlock); 
                } else {
                    workspace.insertBefore(clonedBlock, targetBlock.nextElementSibling);
                }
            } else {
                workspace.appendChild(clonedBlock); 
            }

            deleteIcon.addEventListener("click", function() {
                clonedBlock.remove();
            });
        } else {
           
           if (targetBlock && draggedBlock !== targetBlock) {
                if (event.clientY < targetBlock.getBoundingClientRect().top + targetBlock.offsetHeight / 2) {
                    workspace.insertBefore(draggedBlock, targetBlock); 
                } else {
                    workspace.insertBefore(draggedBlock, targetBlock.nextElementSibling);
                }
            } else {
                workspace.appendChild(draggedBlock); 
            }
        }

        var allBlocks = document.querySelectorAll(".block");
        allBlocks.forEach(function(block) {
            block.classList.remove("dragging-over");
        });
    });

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