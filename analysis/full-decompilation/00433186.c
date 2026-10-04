
void FUN_00433186(char param_1,char param_2,char param_3,char param_4)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  if ('\0' < param_1) {
    iVar1 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if (((param_1 < iVar1) && ('\0' < param_2)) && (iVar3 = (int)param_2, iVar3 < iVar1)) {
      iVar1 = *(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x30 + param_3 * 4) + 0xc) + param_1 * 4);
      bVar2 = *(byte *)(iVar1 + iVar3) & 0xf7;
      if (param_4 != '\0') {
        bVar2 = bVar2 | 8;
      }
      *(byte *)(iVar1 + iVar3) = bVar2;
    }
  }
  return;
}

