
void __thiscall
FUN_005f7802(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x84);
  iVar2 = *(int *)(param_1 + 0x7c);
  FUN_005e491a(param_2,param_3,param_4,param_5);
  iVar3 = (*(int *)(*(int *)(param_1 + 0xd8) + 0x1c) / 4 + -1) / 2;
  *(int *)(param_1 + 0x11c) = iVar3 + -10;
  *(int *)(param_1 + 0x124) = ((*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) - iVar3) + 10;
  if (iVar1 - iVar2 != *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) {
    iVar3 = (**(code **)(*(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)] + 0x68))
                      (*(int *)(param_1 + 0x4c),*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c))
    ;
    *(int *)(param_1 + 0x1a8) = iVar3;
    iVar1 = *(int *)(param_1 + 0x124);
    iVar2 = *(int *)(param_1 + 0x11c);
    *(undefined4 *)(param_1 + 0x1a4) = 0xc;
    while ((iVar1 - iVar2 < iVar3 && (8 < *(int *)(param_1 + 0x1a4)))) {
      iVar3 = *(int *)(param_1 + 0x1a4) + -1;
      *(int *)(param_1 + 0x1a4) = iVar3;
      iVar3 = (**(code **)(*(int *)(&DAT_006f2a74)[iVar3] + 0x68))
                        (*(int *)(param_1 + 0x4c),
                         *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
      *(int *)(param_1 + 0x1a8) = iVar3;
    }
  }
  return;
}

