#include <iosteam>
// ВАЖНО!!! - мы пока не знаем ка присунуть фигуру в программу

namespace topit {
  struct p_t {
     int x, y;
  };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct f_t {p_t aa, bb; };
}
struct IDraw {
  virtual p_t begin() const = 0; //"= 0" - чисто виртуальный метод
  virtual p_t next(p_t) const = 0; // в один момент next должен вернуть begin
  virtual ~IDraw() = default;
};
struct Dot: Draw {
  Dot(int x, int y);
  exlisit Dot(p_t dd);
  p_t begin() const override;
  p_t next(p_t) const override;
  p_t d;
};
size_t points(const IDraw& d, p_t ** pts, size_t s);
f_t frame(const p_t* pts, size_t s);
char * canvas(f_t fr, char fill);
int main()
{
  using topit::IDraw
  using topit::Dot;
  using topit::f_t;
  int err = 0;
  IDraw* shps[3] = {};
  p_t * pts == nullptr;
  size_t s = 0;
  try {
    shps[0] = new Dot(0, 0);
    shps[1] = new Dot(5, 7);
    shps[2] = new Dot(-5, -2);
    // TODO:
    for (size_t i = 0, i < 3; ++i){
      s += points(*(shps[0]), &pts, s);
    }
    f_t fr = frame(pts, s);
    char  * cnv = canvas(fr, '.');
    /*
     [1]достать все точки из фигуры
     [2]прочитать щераничивающий прям.
     [3]пожготовить (canvas) нужного размера
     - заполнить canvas '.'
     [4]нарисовать canvas все точки (которые достали из фигур)
     - будем рисовать '#'
     [5]вывести полотно на экран
    */
    delete [] cnv;
  } catch (...) {
    err = 2;
    std::cerr << "Bad drawing\n";
  delete [] pts;
  delete shps[0];
  delete shps[1];
  delete shps[2];
  return err;
}
bool topit::operator==(p_t a, p_t b){
  return a.x == b.x && a.y == b.y;
}
bool topit::operator!=(p_t a, p_t b){
  return !(a == b);
}
topit::p_t topit::Dot::begin() const{
  return d;
}
topit::Dot::Dot(p_t dd):
  IDraw(),
  d{dd}
{}
topit::Dot::Dot(int x, int y):
  IDraw(),
  d{x, y}
{}
topit::p_t topit::Dot::next(p_t prev) const {
  if (prev != begin()){
    throw std::logic_error("bad impl");
  }
  return d;
}
