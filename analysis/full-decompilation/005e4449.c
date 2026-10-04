
undefined4 __thiscall
FUN_005e4449(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DWORD DVar2;
  bool bVar3;
  
  piVar1 = (int *)FUN_00492d2c();
  if (piVar1 != param_1) goto LAB_005e44e7;
  (**(code **)(*param_1 + 0xfc))(param_2,param_3,param_4);
  FUN_005d9912(param_1);
  if (param_1[0x3e] == 0) {
    bVar3 = false;
LAB_005e44b1:
    FUN_005e46f0(bVar3);
  }
  else if (((param_1[0x3e] == 1) && (param_1[0x3d] != 1)) && ((char)param_1[0x5d] != '\0')) {
    bVar3 = param_1[0x38] == 0;
    goto LAB_005e44b1;
  }
  if (((param_1[0x3d] == 0) || (param_1[0x3d] == 2)) && (*(char *)((int)param_1 + 0x169) != '\0')) {
    DAT_006fe954 = param_1;
    FUN_005e4b04(1);
    FUN_005e473b(2);
  }
LAB_005e44e7:
  (**(code **)(*param_1 + 0x168))();
  if ((*(byte *)(param_1 + 0x55) & 4) == 0) {
    *(undefined1 *)(param_1 + 0x5b) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x5b) = 1;
    DVar2 = timeGetTime();
    param_1[0x57] = DVar2;
  }
  return 1;
}

