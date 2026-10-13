# 第三方素材与参考来源

以下说明记录本项目使用的素材和参考，不对全部项目内容授予统一许可。

## Kenney 地图模型

作者：Kenney。以下三个官方素材包均标注为 **CC0 1.0**；下载包内的许可文件已核对。

许可全文：[Creative Commons CC0 1.0 Universal](https://creativecommons.org/publicdomain/zero/1.0/)。

| 官方素材包 | 本项目使用的原模型 | 地图 |
| --- | --- | --- |
| [City Kit (Industrial)](https://kenney.nl/assets/city-kit-industrial) | `building-k.obj`、`chimney-large.obj`、`shipping-container-c.obj` | 工业港湾货场 |
| [Castle Kit](https://kenney.nl/assets/castle-kit) | `tower-square.obj`、`wall.obj`、`rocks-large.obj` | 遗迹回廊 |
| [Space Station Kit](https://kenney.nl/assets/space-station-kit) | `computer-wide.obj`、`wall-pillar.obj`、`container-tall.obj` | 星港前哨 |

这九个模型经过坐标归一化、退化三角形清理、三角形法线生成和原始调色纹理的顶点颜色烘焙，随后内嵌到游戏。后三张地图的布局、碰撞与游戏配置由本项目另行制作。

## AK 枪声音频

作者：Felix Blume。

来源：[Rifle Gun Shot AK47. close recording in a shooting range.](https://freesound.org/people/felix.blume/sounds/136399/)。该页面标注的许可为 [CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/)。

本项目从该页面提供的公开试听音频中截取一个 300 毫秒单发片段，进行轻度风声清理、尾音收短和边界淡入淡出，转换为 24kHz 单声道 PCM16 并内嵌。这里使用的是公开试听版本，不是原始录音 WAV。

## AK 压枪轨迹参考

参考页面：[AimFinder 压枪训练](https://aimfinder.pro/zh/pattern-training)。

本项目参考公开展示的 AK 30 发点位与 600 RPM 射速，并转换为游戏的弹道角度。未确认该参考数据的开放许可，本项目不为其声明 CC0、MIT 或其他开源许可。

## 爆头击中音效

来源：随项目提供的音频文件。原作者与许可未另行确认，本项目不为这段音频声明开放许可。

该音效保留完整的约 2.286 秒攻击段、尾音和双声道，转换为 48kHz 立体声 PCM16 后内嵌到游戏；播放时保持原音高。
