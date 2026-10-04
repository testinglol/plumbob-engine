
void __fastcall FUN_00476c48(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_006e54b0;
  while( true ) {
    if (iVar1 == 0) {
      *(int *)(param_1 + 4) = DAT_006e54b0;
      DAT_006e54b0 = param_1;
      return;
    }
    if (iVar1 == param_1) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return;
}

