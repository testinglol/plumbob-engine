
char __thiscall FUN_005e86ec(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  
  cVar1 = FUN_005dbf32();
  if (cVar1 == '\0') {
LAB_005e8797:
    cVar1 = '\0';
  }
  else {
    *(undefined4 *)(param_1 + 0xf4) = 0;
    piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    uVar3 = (**(code **)(*piVar2 + 0x38))(0xff,0,0);
    *(uint *)(param_1 + 0xf8) = uVar3 & 0xffff;
    if (DAT_006fea20 == (int *)0x0) {
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      DAT_006fea20 = (int *)(**(code **)(*piVar2 + 0x10))(1,7,0,0);
      if (DAT_006fea20 == (int *)0x0) goto LAB_005e8797;
      (**(code **)(*DAT_006fea20 + 0x20))(*(undefined4 *)(param_1 + 0xf4));
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    FUN_005e87ae(param_2,*(undefined4 *)(param_1 + 0xe4));
    uVar4 = FUN_005dd5e1(0xff,0xff,0xe0);
    *(undefined4 *)(param_1 + 100) = uVar4;
  }
  return cVar1;
}

