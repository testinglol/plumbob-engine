
void __fastcall FUN_0042349d(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 400);
  if (*(int *)(param_1 + 400) == 0) {
    iVar2 = param_1;
  }
  if (iVar2 == param_1) {
    iVar2 = *(int *)(iVar2 + 0x18c);
  }
  FUN_00422909();
  if (iVar2 != 0) {
    FUN_004234de();
  }
  cVar1 = FUN_00432644();
  if (cVar1 != '\0') {
    FUN_004234de();
  }
  return;
}

