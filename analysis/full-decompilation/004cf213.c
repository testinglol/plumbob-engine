
undefined4 FUN_004cf213(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(DAT_006e486c + 0x18) + 0xc);
  return CONCAT31((int3)((uint)piVar1 >> 8),
                  (*(int *)(*(int *)(DAT_006e486c + 0x18) + 0x10) - *piVar1 & 0xfffffffcU) != 0);
}

