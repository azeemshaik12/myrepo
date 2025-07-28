import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 360
    height: 300
    visible: true
    title: "Snapping ListView (Variable Height)"

    ListView {
        id: listView
        anchors.fill: parent
        model: 10
        clip: true
        interactive: true
        snapMode: ListView.NoSnap

        delegate: Item {
            id: itemRoot
            width: listView.width
            height: 80 + (index % 3) * 40  // variable height

            Rectangle {
                anchors.fill: parent
                color: index % 2 === 0 ? "#ddeeff" : "#ccddee"
                border.color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Item " + index
                }
            }

            Component.onCompleted: {
                // Save this item’s height so we can compute snap
                listView.itemHeights[index] = height;
            }
        }

        ScrollBar.vertical: ScrollBar {}

        property var itemHeights: []

        function findNearestIndex(yPos) {
            var sum = 0;
            for (var i = 0; i < itemHeights.length; ++i) {
                var h = itemHeights[i] || 0;
                var mid = sum + h / 2;
                if (yPos < mid)
                    return i;
                sum += h;
            }
            return itemHeights.length - 1;
        }

        onMovementEnded: {
            var nearestIndex = findNearestIndex(contentY);
            positionViewAtIndex(nearestIndex, ListView.Beginning);
        }
    }
}
/*
// Function to find the index of the item whose center is nearest to the given scroll position (yPos)
function findNearestIndex(yPos) {
    var sum = 0;  // Running total of item heights — keeps track of current vertical position

    // Loop through all item heights to find the nearest item to yPos
    for (var i = 0; i < itemHeights.length; ++i) {
        var h = itemHeights[i] || 0;  // Get the height of item at index i, default to 0 if undefined

        var mid = sum + h / 2;  // Calculate the vertical midpoint of the current item

        // If current scroll position is above the midpoint of this item,
        // it means this item is the nearest one to snap to
        if (yPos < mid)
            return i;

        sum += h;  // Move the sum pointer down by this item's height
    }

    // If yPos is below all midpoints, return the last item index
    return itemHeights.length - 1;
}

*/
