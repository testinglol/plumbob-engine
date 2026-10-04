
void FUN_004e9b56(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if ((-1 < param_1) && (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44)) {
    puVar1 = (undefined4 *)FUN_004e8a7a();
    if ((puVar1 != (undefined4 *)0x0) && (((byte)puVar1[0x2d] & 0xc) == 4)) {
      FUN_00457ea7();
      FUN_005d499c(param_2);
      FUN_004063b5(*puVar1,CONCAT22((short)((uint)puVar1[0x18] >> 0x10),
                                    *(undefined2 *)(puVar1[0x18] + 0x52)));
    }
  }
  return;
}

