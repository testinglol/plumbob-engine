
undefined4 __thiscall FUN_0044d0b7(int param_1,undefined4 param_2,uint param_3)

{
  short *psVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_28 = 5;
  local_24 = 6;
  local_20 = 7;
  local_1c = 8;
  local_18 = 9;
  local_14 = 0xd;
  local_10 = 0xe;
  local_c = 0xf;
  local_8 = 0;
  psVar1 = (short *)(param_3 + 4);
  if (*psVar1 == 1) {
    param_3 = (uint)*(ushort *)(param_3 + 6);
    iVar5 = FUN_004750a6();
    iVar5 = FUN_00407498((int)*(short *)(iVar5 + 4));
  }
  else {
    iVar5 = param_1;
    param_3 = (uint)*(ushort *)(param_3 + 6);
    if (*psVar1 == 2) goto LAB_0044d1a7;
  }
  if ((iVar5 != 0) && (*(short *)(*(int *)(iVar5 + 0x118) + 0x12) == 2)) {
    if ((-1 < (int)param_3) && ((int)param_3 < 3)) {
      DAT_006e5054 = FUN_0045d291(0);
      FUN_0063560a(&local_28,8,4,&LAB_0044d07b);
      puVar4 = &local_28;
      puVar3 = (undefined2 *)(param_1 + 0x3a);
      iVar5 = 5;
      do {
        uVar2 = *(undefined2 *)puVar4;
        puVar4 = puVar4 + 1;
        *puVar3 = uVar2;
        puVar3 = puVar3 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      return 1;
    }
    param_3 = 0x1e;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_3,&DAT_00698f30);
  }
LAB_0044d1a7:
  param_3 = 10;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&param_3,&DAT_00698f30);
}

