
bool __fastcall FUN_005dc217(int param_1)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  
  bVar3 = 0;
  while (piVar1 = *(int **)(param_1 + 0x38), (int *)*piVar1 != piVar1) {
    cVar2 = FUN_005da4c7(*(undefined4 *)(*piVar1 + 8));
    bVar3 = bVar3 | 1U - (cVar2 != '\0');
  }
  return bVar3 == 0;
}

