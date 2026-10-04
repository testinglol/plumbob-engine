
uint FUN_004e9982(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(int *)(*DAT_006e486c + 0x10) != 0) {
    uVar1 = FUN_004e8d71(param_1);
    uVar2 = FUN_00410285(uVar1);
    return uVar2;
  }
  return *DAT_006e486c & 0xffffff00;
}

