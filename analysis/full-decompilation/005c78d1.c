
bool __thiscall FUN_005c78d1(uint *param_1,uint param_2)

{
  void *pvVar1;
  
  FUN_006321f0(param_1[1]);
  *param_1 = param_2;
  pvVar1 = operator_new(param_2);
  param_1[1] = (uint)pvVar1;
  return pvVar1 != (void *)0x0;
}

