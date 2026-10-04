
void __fastcall FUN_004f778b(int param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_004a6b07();
  if (*(int *)(param_1 + 0x84) != 0) {
    iVar1 = FUN_004d4090();
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004d4090();
      (**(code **)(*piVar2 + 0x38))();
    }
  }
  return;
}

