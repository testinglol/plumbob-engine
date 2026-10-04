
int __fastcall FUN_00440389(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if ((*(char *)(param_1 + 0x44) != '\0') ||
     (iVar1 = *(int *)(DAT_006e54d8 + 0x84), iVar1 != *(int *)(param_1 + 0x48))) {
    FUN_004403d7(param_1,iVar1);
  }
  return param_1 + 0x4c;
}

