import QtQuick
import QtQuick3D
import QtQuick.Controls
//find_package(Qt6 REQUIRED COMPONENTS Quick Quick3D)
Window {
    width: 800
    height: 600
    visible: true
    title: "3D Mesh Viewer with Mouse Interaction"

    property real lastX: 0
    property real lastY: 0
    property real yaw: 0
    property real pitch: 0
    property real distance: 600

    View3D {
        anchors.fill: parent

        environment: SceneEnvironment {
            backgroundMode: SceneEnvironment.Color
            clearColor: "#202020"
        }

        PerspectiveCamera {
            id: cam
            position: Qt.vector3d(0, 0, distance)
           // lookAt: Qt.vector3d(0, 0, 0)
        }

        Model {
            id: suzanne
            source: "file:///C:/Qt/Examples/Qt-6.8.1/quick3d/particles3d/meshes/suzanne.mesh"
            scale: Qt.vector3d(100, 100, 100)

            materials: PrincipledMaterial {
                baseColor: "lightblue"
                roughness: 0.5
            }
        }

        DirectionalLight {
            eulerRotation.x: -45
            eulerRotation.y: -45
        }

        // Mouse area for rotation and zoom
        MouseArea {
            anchors.fill: parent
            drag.target: null
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            hoverEnabled: true

            onPressed: {
                lastX = mouse.x
                lastY = mouse.y
            }

            onPositionChanged: {
                if (mouse.buttons & Qt.LeftButton) {
                    // Orbit rotation
                    yaw += (mouse.x - lastX) * 0.5
                    pitch += (mouse.y - lastY) * 0.5
                    pitch = Math.max(-90, Math.min(90, pitch)) // Clamp pitch
                    lastX = mouse.x
                    lastY = mouse.y

                    var radYaw = yaw * Math.PI / 180
                    var radPitch = pitch * Math.PI / 180
                    cam.position = Qt.vector3d(
                        distance * Math.sin(radYaw) * Math.cos(radPitch),
                        distance * Math.sin(radPitch),
                        distance * Math.cos(radYaw) * Math.cos(radPitch)
                    )
                   // cam.lookAt = Qt.vector3d(0, 0, 0)
                }
            }

            onWheel: {
                // Zoom
                distance *= (wheel.angleDelta.y > 0) ? 0.9 : 1.1
                distance = Math.max(50, Math.min(2000, distance)) // clamp distance

                var radYaw = yaw * Math.PI / 180
                var radPitch = pitch * Math.PI / 180
                cam.position = Qt.vector3d(
                    distance * Math.sin(radYaw) * Math.cos(radPitch),
                    distance * Math.sin(radPitch),
                    distance * Math.cos(radYaw) * Math.cos(radPitch)
                )
               // cam.lookAt = Qt.vector3d(0, 0, 0)
            }
        }
    }
}
