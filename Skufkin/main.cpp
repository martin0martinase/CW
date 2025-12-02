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
}
int main()
{
  using topit::p_t;
  IDraw * p = new Dot(10, 10);
  IDraw
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
