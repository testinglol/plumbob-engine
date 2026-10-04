
void __fastcall FUN_0046f9f6(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (**(code **)*param_1)();
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      cVar1 = *(char *)(param_1[1] + iVar3);
      if (('@' < cVar1) && (cVar1 < '[')) {
        *(char *)(param_1[1] + iVar3) = cVar1 + ' ';
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}

