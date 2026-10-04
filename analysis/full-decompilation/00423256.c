
void __thiscall FUN_00423256(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00434353(param_2,param_3,param_4);
  FUN_00464a4e(param_1 + 0x1a0,1);
  FUN_00464a4e(param_1 + 0x1a4,1);
  if (0x39 < param_3) {
    FUN_00464a4e(param_1 + 0x1a8,1);
  }
  if (0x27 < param_3) {
    FUN_00464a4e(param_1 + 0x194,1);
    FUN_00464a4e(param_1 + 0x198,1);
    FUN_00464a4e(param_1 + 0x19c,1);
  }
  iVar1 = *(int *)(param_1 + 400);
  if (iVar1 == 0) {
    param_4 = 0;
  }
  else {
    param_4 = CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0xf0));
  }
  FUN_00464973(&param_4,1);
  if ((*(int *)(param_2 + 0xc) == 0) && ((short)param_4 != 0)) {
    uVar2 = FUN_00407498((int)(short)param_4);
    FUN_004228dc(uVar2);
  }
  return;
}

