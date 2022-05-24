# **JUMP KING**

**Dự án game môn Lập trình nâng cao INT2215 1**

**Tên sinh viên: Bùi Đức Luân**

**MSV: 21020775**

**Lớp: K66CC**

### **1. Hướng dẫn cài đặt: cách lấy chương trình về, tất cả các câu lệnh, cài đặt để có thể chạy được chương trình.**

Bước 1: Truy cập link https://github.com/LuaanAlphaIT/LuaanAlphaIT.
![alt](https://f14.photo.talk.zdn.vn/4854267835492606080/e2f80e867bdcbb82e2cd.jpg)

Bước 2: Vào Code - vào Download ZIP - Giải nén file vừa tải.
![alt](https://f25-zpc.zdn.vn/4477391188524102423/622a918aedd02d8e74c1.jpg)

Bước 3: 

      Vào file vừa giải nén, chọn Debug, chọn Jump_King.exe để chơi game.
![alt](https://f3.photo.talk.zdn.vn/4574145832592386618/9f8c87a1e1fb21a578ea.jpg)
      
      hoặc

      Vào file vừa giải nén, chọn Jump_King.sln để chạy trên Visual Studio.
![alt](https://f17-zpc.zdn.vn/14056306441103204/f3fa03528633466d1f22.jpg)


### **2. Mô tả chung về trò chơi, các ý tưởng chính.**

Trò chơi bao gồm các thành phần: Nhân vật, vật cản.

Hướng dẫn: Người chơi điều khiển nhân vật bằng các phím để nhân vật đến đích (trước chỗ công chúa ở trên cao), nếu lỡ bị ngã sẽ phải nhảy lại. Nhảy qua một đoạn cảnh quan sẽ thay đổi, người chơi cần phải lên để biết được vật cản tiếp theo nhảy đến. Người chơi chiến thắng khi đến được đích.
![alt](https://f17-zpc.zdn.vn/3264803302789629677/879e4b7bccce0d9054df.jpg)

      Phím X: Di chuyển sang bên trái.

      Phím Y: Di chuyển sang bên phải.

      Phím UP: Nhảy lên trên.

      Phím LEFT: Nhảy sang bên trái, giữ phím càng lâu nhảy càng xa.

      Phím RIGHT: Nhảy sang bên phải, giữ phím càng lâu nhảy càng xa.

Các ý tưởng: Game dựa trên trò chơi Jump King được phát triển bởi Nexile, nhân vật sẽ nhảy từ nơi có cảnh quan mùa hè, đến mùa thu, đến mùa đông, đến núi tuyết, đến bầu trời, đến lâu đài trên mây, đến đỉnh tháp lâu đài nơi công chúa đang đứng chờ.

### **3. Mô tả các chức năng đã cài đặt, kèm video minh họa (chèn link video youtube)**

Các chức năng:

      Chơi lại trò chơi sau khi đã chiến thắng: sau khi chiến thắng có thể nhấp Y để chơi lại game.

      Bật tắt âm thanh trò chơi: nhấp O để bật, tắt âm thanh của game.

      Thoát game: nhấp N để thoát game ở menu và khi đang chơi, nhấp X để thoát khi ở màn hình chiến thắng.

      Lưu lại vị trí người chơi lúc thoát game: khi thoát trò chơi, vị trí nhân vật sẽ được lưu lại và khi vào lại game nhân vật vẫn ở vị trí đó.

Video minh họa: https://www.youtube.com/watch?v=2E-RGGl0fZA.

### **4. Các kỹ thuật lập trình được sử dụng trong chương trình (mảng, con trỏ, cấu trúc, lớp, đồ họa ...)**

class:

      BaseObject: lưu ảnh và vị trí của background.
      
      TileMat: class kế thừa của BaseObject.
      
      GameMap: lưu ảnh vật cản và vị trí của vật cản.
      
      MainObject: lưu hình ảnh, xử lí chuyển động nhân vật, va chạm và hiệu ứng âm thanh.
      
      ImgTimer: xử lí thời gian của chương trình.
      
struct:
      
      Map: lưu mảng tile map của vật cản.
      
      Input: trạng thái chuyển động của nhân vật.
      
Con trỏ: sử dụng các biến trong SDL.

Mảng: các mảng hiệu ứng âm thanh, hình ảnh, tile map.

Chia tách file: chia tách các file để dễ quản lí chương trình.

Đồ họa: thư viện SDL_image.h của SDL.

Âm thanh: Thư viện SDL_mixer.h của SDL.

Xử lí sự kiện: bắt sựu kiện SDL_PollEvent của SDL.

Tệp: dùng để lấy vị trí đã lưu của nhân vật, lưu lại vị trí nhân vật khi thoát chương trình, reset lại vị trí nhân vật khi chơi lại.

### **5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình**

Kết luận: Game có đồ họa, âm thanh khá ổn, xử lí va chạm tốt, chương trình game chạy mượt.

Nguồn :

      Cách sử dụng SDL : https://lazyfoo.net/tutorials/SDL/.

      Hình ảnh: Em cắt ghép chỉnh sửa từ nhiều nguồn khác nhau trên mạng.

      Âm thanh: Em tải âm thanh trên youtube

Hướng phát triển: Làm thêm nhiều màn khác, tạo thêm nhiều chế độ như động đất, gió thổi, băng trơn, cát lún, ..., chỉnh sửa tile map để game khó chơi, cải thiện va chạm khi đâm vào vật cản, hiệu ứng nhân vật, cải thiện đồ họa.

Các điều tâm đắc rút ra: Em cải thiện được khả năng code, biết chia tách file .cpp và .h để dễ quane lí, tìm kiếm thông tin, nguồn tài liệu, ngoài ra em còn thấy tầm quan trọng của tiếng anh trong việc học tập.











