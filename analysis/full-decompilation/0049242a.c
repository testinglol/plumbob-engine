
void __fastcall FUN_0049242a(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(DAT_006e54d8 + 0x10);
  if (0 < iVar1) {
    local_c = (int *)(param_1 + 0x402c);
    do {
      iVar3 = 0;
      piVar4 = local_c;
      do {
        cVar2 = (char)iVar3;
        iVar3 = iVar3 + 1;
        piVar4[-0x1000] =
             *(int *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) + (char)local_8 * 4) +
                     cVar2 * 4);
        *piVar4 = (int)*(char *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x1c) + 0xc) +
                                         (char)local_8 * 4) + (int)cVar2);
        piVar4 = piVar4 + 1;
      } while (iVar3 < iVar1);
      local_8 = local_8 + 1;
      local_c = local_c + 0x40;
    } while (local_8 < iVar1);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}

