
undefined4 __thiscall FUN_005eb2a6(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  int *local_c;
  undefined4 uStack_8;
  
  if (*(char *)((int)param_1 + 0x14d) != '\0') {
    if ((char)param_1[0x55] != '\0') {
      param_3 = 0;
      param_2 = 0;
      FUN_005d9928(&param_3,&param_2);
      iVar4 = param_3 - param_1[0x4f];
      param_3 = param_2 - param_1[0x50];
      param_2 = iVar4;
    }
    iVar4 = param_1[0x35];
    iVar5 = (**(code **)(*param_1 + 0x1c0))(param_2,param_3);
    param_1[0x35] = iVar5;
    if (iVar5 != iVar4) {
      if ((iVar4 != -1) && (*(int *)(param_1[100] + 0xc + iVar4 * 0x28) != 0)) {
        FUN_005e46f0(0);
      }
      if (-1 < param_1[0x35]) {
        if (*(int *)(param_1[100] + 0xc + param_1[0x35] * 0x28) != 0) {
          FUN_005e46f0(1);
        }
        if (param_1[0x5f] != 0) {
          FUN_0057a14d(s_UI_piemenu_highlight_006d7828);
        }
      }
      (**(code **)(*param_1 + 0x1ac))(param_1[0x35],0);
    }
    if ((((param_1[0x5e] != 0) && (uVar1 = param_1[0x5d], uVar1 != 0)) && (param_1[0x35] == -1)) &&
       (uStack_8 = 0, local_c = (int *)uVar1, (float)uVar1 < (float)param_1[0x59])) {
      (**(code **)(*param_1 + 0x1ac))(0xffffffff,1);
    }
    puVar2 = (undefined4 *)param_1[0x12];
    if ((puVar2 != (undefined4 *)0x0) && (cVar3 = FUN_005da398(puVar2), cVar3 != '\0')) {
      local_14 = 3;
      local_10 = 0xd;
      uStack_8 = 0;
      local_c = param_1;
      (**(code **)*puVar2)(&local_14);
    }
  }
  return 1;
}

