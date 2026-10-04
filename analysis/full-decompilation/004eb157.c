
void FUN_004eb157(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (-1 < param_1) {
    if (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44) {
      iVar1 = FUN_004e8a7a();
      FUN_00406466(0,DAT_00666580);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)thunk_FUN_00457ea7();
        FUN_005d49b7(*puVar2);
      }
    }
  }
  return;
}

