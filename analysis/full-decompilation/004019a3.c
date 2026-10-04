
exception * __thiscall FUN_004019a3(exception *param_1,byte param_2)

{
  exception::~exception(param_1);
  if ((param_2 & 1) != 0) {
    FUN_006321f0(param_1);
  }
  return param_1;
}

