
void __thiscall FUN_00565b68(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_2 + -0x51 < 0) || (8 < param_2 + -0x51)) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[param_2 + 0xa5] + 0x194;
  }
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x24) == -1) {
      if (*(int *)(iVar2 + 0x18) == 0) {
        FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
        (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))(&DAT_006f5da4,&DAT_006f5d98,0,0);
        FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
        return;
      }
      iVar2 = FUN_004f6994(DAT_006f5e64,DAT_006f5e58,2,0);
      if (iVar2 == 4) {
        FUN_0057a7f7(s_UI_Nhood_bdoze_demolish_006cda1c,0xfffffffc);
        iVar2 = param_1[0x1a];
        uVar3 = FUN_005e74ca(3);
        FUN_005dde6d(uVar3);
        cVar1 = FUN_004e2b07(param_2,1);
        FUN_005dde6d(iVar2);
        FUN_005db1e2();
        if (cVar1 == '\0') {
          FUN_004f6994(DAT_006f5edc,DAT_006f5ed0,0,0);
          return;
        }
      }
      FUN_0054ebd3();
    }
    (**(code **)(*param_1 + 0x168))();
  }
  return;
}

