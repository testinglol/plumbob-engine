
void __thiscall FUN_005e452a(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_00492d2c();
  if (piVar2 == param_1) {
    if ((((param_2 < 0) || (param_1[0x21] - param_1[0x1f] <= param_2)) || (param_3 < 0)) ||
       (param_1[0x22] - param_1[0x20] <= param_3)) {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if (cVar1 != *(char *)((int)param_1 + 0x169)) {
      if (cVar1 == '\0') {
        (**(code **)(*param_1 + 0x10c))(param_2,param_3,param_1);
      }
      else {
        (**(code **)(*param_1 + 0x108))();
      }
    }
  }
  FUN_005dd854(param_2,param_3,param_4);
  return;
}

