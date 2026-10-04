
undefined4 __thiscall FUN_0052e8f2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 == 1) {
    for (piVar3 = (int *)param_1[0x37]; (piVar3 != (int *)param_1[0x38] && (*piVar3 != param_3));
        piVar3 = piVar3 + 1) {
    }
    if (piVar3 != (int *)param_1[0x38]) {
      param_3 = 0;
      iVar4 = (int)piVar3 - param_1[0x37] >> 2;
      if (0 < (int)(param_1[0x38] - param_1[0x37] & 0xfffffffcU)) {
        do {
          FUN_005e46f0(iVar4 == param_3);
          param_3 = param_3 + 1;
        } while (param_3 < param_1[0x38] - param_1[0x37] >> 2);
      }
      iVar1 = *(int *)(param_1[0x3b] + 0x158);
      if ((iVar1 != 0) && (param_1[0x45] != 0)) {
        if (*(char *)(iVar1 + 0xe0) == '\0') {
          *(int *)(param_1[0x45] + 0x14) = *piVar3;
          FUN_00510747(*(undefined4 *)(param_1[0x3c] + iVar4 * 0xc));
          FUN_00510775(*(undefined4 *)(param_1[0x3f] + iVar4 * 0xc));
          FUN_0050fb20(param_1[0x45],param_1);
        }
        else if (*(int *)(*(int *)(iVar1 + 0x10c) + 0x14) == *piVar3) {
          FUN_0050fc0a(1);
        }
        else {
          FUN_005e46f0(0);
          *(int *)(param_1[0x45] + 0x14) = *piVar3;
          FUN_00510747(*(undefined4 *)(param_1[0x3c] + iVar4 * 0xc));
          FUN_00510775(*(undefined4 *)(param_1[0x3f] + iVar4 * 0xc));
          FUN_0050fc6a(param_1[0x45]);
        }
      }
      return 1;
    }
    param_2 = 1;
  }
  else if (param_2 == 0x13) {
    uVar2 = (**(code **)(*param_1 + 300))(1,param_3);
    return uVar2;
  }
  uVar2 = FUN_005dd97f(param_2,param_3);
  return uVar2;
}

