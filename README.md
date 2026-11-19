# 🎮 MyGame — لعبة C++ بـ 100 مستوى

مشروع لعبة مكتوب بـ **C++20** ومنظم بشكل احترافي، يحتوي على **100 مستوى** تُحمَّل ديناميكيًا من ملفات JSON، بدون كتابة 100 دالة منفصلة. الهدف من المشروع هو إظهار **الهيكلة الصحيحة** لمشروع C++ كبير: فصل الوحدات، ترجمة منفصلة، ونظام بناء عبر CMake.

---

## ✨ المميزات

- ✅ **هيكلة نظيفة**: فصل `include/` عن `src/` عن `apps/`.
- ✅ **ترجمة منفصلة**: كل وحدة (Core, Levels, Entities) في ملفات مستقلة.
- ✅ **مكتبة `game_core`**: المنطق معزول عن نقطة الدخول، مما يسهل الاختبار وإعادة الاستخدام.
- ✅ **مستويات ديناميكية**: 100 مستوى تُقرأ من ملفات JSON بدلًا من كود ثابت.
- ✅ **قابل للتوسع**: إضافة المستوى 101 = إنشاء ملف JSON فقط.
- ✅ **جاهز للرسوميات**: يمكن ربط SFML أو SDL لاحقًا دون تغيير المنطق.
- ✅ **CMake**: بناء بسيط ومحمول عبر المنصات.

---

## 📁 هيكل المشروع

```text
my_game/
├── CMakeLists.txt              # ملف البناء الرئيسي
├── README.md
├── include/
│   └── my_game/
│       ├── core/
│       │   ├── Game.h          # حلقة اللعبة الرئيسية
│       │   └── Level.h         # تعريف المستوى
│       ├── levels/
│       │   └── LevelManager.h  # تحميل وإدارة المستويات
│       └── entities/
│           └── Player.h        # اللاعب
├── src/
│   ├── core/
│   │   ├── Game.cpp
│   │   └── Level.cpp
│   ├── levels/
│   │   └── LevelManager.cpp
│   └── entities/
│       └── Player.cpp
├── apps/
│   └── main.cpp                # نقطة الدخول (صغيرة جدًا)
├── levels_data/
│   ├── level_01.json
│   ├── level_02.json
│   └── ...
├── tests/
│   └── CMakeLists.txt
└── third_party/                # مكتبات خارجية (اختياري)
```

---

## 🛠️ المتطلبات

| الأداة | الإصدار الموصى به |
|--------|-------------------|
| مترجم C++ | يدعم C++20 (GCC 10+, Clang 12+, MSVC 19.30+) |
| CMake | 3.20 أو أحدث |
| Git | أي إصدار حديث |

---

## 🚀 البناء والتشغيل

```bash
# 1. استنساخ المشروع
git clone https://github.com/USERNAME/my_game.git
cd my_game

# 2. إنشاء مجلد البناء
mkdir build && cd build

# 3. توليد ملفات البناء
cmake ..

# 4. التجميع
cmake --build .

# 5. التشغيل
./my_game        # Linux / macOS
# أو
my_game.exe      # Windows
```

---

## 🧩 كيف تُدار المستويات؟

كل مستوى عبارة عن ملف JSON في مجلد `levels_data/`. مثال `level_01.json`:

```json
{
  "id": 1,
  "name": "البداية",
  "enemies": [
    { "type": "slime", "x": 100, "y": 200 }
  ],
  "goal": { "x": 800, "y": 600 },
  "timeLimit": 60
}
```

`LevelManager` يقرأ الملفات ديناميكيًا:

```cpp
void LevelManager::loadLevel(int levelNumber) {
    std::string path = "levels_data/level_" +
                       std::to_string(levelNumber) + ".json";
    currentLevel = Level::fromFile(path);
}
```

### ➕ إضافة مستوى جديد

1. أنشئ ملف `levels_data/level_101.json`.
2. اتبع نفس البنية أعلاه.
3. لا حاجة لإعادة ترجمة الكود ✅.

---

## 🖼️ إضافة رسوميات (اختياري)

المنطق معزول عن العرض. لإضافة SFML مثلًا:

**في `CMakeLists.txt`:**

```cmake
find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
target_link_libraries(game_core PUBLIC sfml-graphics sfml-window)
```

ثم أضف طبقة عرض (Renderer) تستدعي دوال `Game` و `Level` دون تعديل منطق اللعبة.

---

## 🧪 الاختبارات (اختياري)

```bash
cd build
ctest --output-on-failure
```

---

## 🤝 المساهمة

1. Fork المشروع.
2. أنشئ فرعًا جديدًا: `git checkout -b feature/my-feature`.
3. اعمل commits واضحة: `git commit -m "Add: level 101 JSON"`.
4. Push: `git push origin feature/my-feature`.
5. افتح Pull Request.

**قواعد المساهمة:**
- اتبع أسلوب الكود الموجود.
- استخدم `#pragma once` في كل header.
- ضع كل مسؤولية في ملف منفصل.
- لا تكتب منطقًا داخل `main.cpp`.

---

## 📜 الترخيص

هذا المشروع مرخص تحت **MIT License** — راجع ملف [LICENSE](LICENSE) للتفاصيل.

---

## 📬 التواصل

- 🐛 للإبلاغ عن مشاكل: [Issues](../../issues)
- 💡 لأفكار جديدة: [Discussions](../../discussions)

---

<p align="center">
  صُنع بـ ❤️ باستعمال C++20 و CMake
</p>
