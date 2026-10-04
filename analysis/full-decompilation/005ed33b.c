
bool __fastcall FUN_005ed33b(int *param_1)

{
  char cVar1;
  BOOL BVar2;
  
  cVar1 = (**(code **)(*param_1 + 4))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 8))();
  }
  BVar2 = DeleteFileA((LPCSTR)param_1[1]);
  return BVar2 != 0;
}

