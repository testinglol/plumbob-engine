
undefined4 __thiscall FUN_005d79cc(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if (((param_1[0x3e] != 0) && (cVar1 = FUN_005f034e(), cVar1 != '\0')) && (DAT_006feca4 != 1)) {
    FUN_005f0352(1);
  }
  cVar1 = FUN_00472342();
  if (cVar1 == '\x10') {
    if (((byte)param_3 & 3) != 3) goto LAB_005d7a3d;
    if (param_2 == 0x62) goto LAB_005d7a2d;
    bVar3 = param_2 == 0x42;
  }
  else {
    if (((byte)param_3 & 3) != 3) goto LAB_005d7a3d;
    if (param_2 == 99) goto LAB_005d7a2d;
    bVar3 = param_2 == 0x43;
  }
  if (bVar3) {
LAB_005d7a2d:
    (**(code **)(*param_1 + 0x1c4))(1);
    return 1;
  }
LAB_005d7a3d:
  uVar2 = FUN_005dd72f(param_2,param_3);
  return uVar2;
}

