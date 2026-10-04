
bool __thiscall FUN_005ed35f(int *param_1,undefined4 param_2)

{
  LPCSTR lpExistingFileName;
  char cVar1;
  LPCSTR lpNewFileName;
  BOOL BVar2;
  
  cVar1 = (**(code **)(*param_1 + 4))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 8))();
  }
  lpExistingFileName = (LPCSTR)param_1[1];
  lpNewFileName = (LPCSTR)FUN_004096c2();
  BVar2 = MoveFileA(lpExistingFileName,lpNewFileName);
  FUN_005d499c(param_2);
  return BVar2 != 0;
}

