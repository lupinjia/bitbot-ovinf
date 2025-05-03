# bitbot-ovinf

Usage:

1. Clone the repository.
2. Install [OpenVINO](https://storage.openvinotoolkit.org/repositories/openvino/packages/).
3. Modify `CMakeLists.txt`, `<robot_name>.xml` and `<robot_name>.yaml` config file in `config/<robot_name>` folder.
4. Build the project.

```shell
# Mujoco simulation
cmake ..
# Deploy
cmake .. -DDEPLOY=ON
```

Note:

HHFC has an <mark>IMU whose x-axis is backward and z-axis is downward</mark>. `bitbot-cifx` source code in HHFC is modified to make frontend display the correct orientation of the robot. `bitbot-cifx` in `dependences` folder is the original one.

