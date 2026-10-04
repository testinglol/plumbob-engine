
undefined4 FUN_004227a9(void)

{
  int iVar1;
  undefined4 local_14 [4];
  
  local_14[1] = 0;
  local_14[0] = 2;
  local_14[2] = 6;
  iVar1 = *(int *)(DAT_006e54d8 + 0x84);
  local_14[3] = 4;
  if ((-1 < iVar1) && (iVar1 < 4)) {
    return local_14[iVar1];
  }
  return 0;
}

