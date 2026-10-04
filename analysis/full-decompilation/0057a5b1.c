
void __fastcall FUN_0057a5b1(char *param_1)

{
  int iVar1;
  
  if (((param_1[0x14] != '\0') && (*param_1 != '\0')) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00572b70();
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 != 0) {
      FUN_005715ab();
      FUN_006321f0(iVar1);
    }
    param_1[0xc] = '\0';
    param_1[0xd] = '\0';
    param_1[0xe] = '\0';
    param_1[0xf] = '\0';
  }
  return;
}

