
void __thiscall FUN_0062e335(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar3 = param_1 + (int)param_2 * 0xa0 + 0x34e4 + param_3 * 0x48;
  FUN_0062e08d(param_2,param_3);
  if ((*(int *)(iVar3 + 0x10) == 0) || (*(int *)(iVar3 + 0x14) != 2)) {
    puVar4 = &DAT_006ff870;
    param_1 = (int)param_2 * 0xf8 + param_1;
    puVar2 = (undefined4 *)(param_1 + 0x3614);
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (puVar4 < &DAT_006ff8c4);
    *(undefined4 *)(param_1 + 0x3668) = 0;
    *(undefined4 *)(param_1 + 0x366c) = 0;
  }
  else if (*(int *)(iVar3 + 0x18) == 0) {
    iVar3 = (int)param_2 * 0xf8;
    param_2 = &DAT_006ff870;
    param_3 = 0xc;
    iVar3 = iVar3 + param_1;
    puVar2 = (undefined4 *)(iVar3 + 0x3670);
    do {
      puVar4 = param_2 + 3;
      iVar5 = 3;
      puVar6 = puVar2;
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 0xd;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      puVar2 = puVar2 + 1;
      param_3 = param_3 + -1;
      param_2 = puVar4;
    } while (param_3 != 0);
    puVar2 = (undefined4 *)(iVar3 + 0x36a0);
    iVar3 = 3;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 0xd;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    puVar4 = &DAT_006ff870;
    param_1 = (int)param_2 * 0xf8 + param_1;
    iVar3 = 8;
    puVar2 = (undefined4 *)(param_1 + 0x3614);
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    param_2 = &DAT_006ff890;
    puVar2 = (undefined4 *)(param_1 + 0x367c);
    param_3 = 9;
    do {
      puVar4 = param_2 + 3;
      iVar3 = 3;
      puVar6 = puVar2;
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 0xd;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      puVar2 = puVar2 + 1;
      param_3 = param_3 + -1;
      param_2 = puVar4;
    } while (param_3 != 0);
    puVar2 = (undefined4 *)(param_1 + 0x36a0);
    iVar3 = 3;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 0xd;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

