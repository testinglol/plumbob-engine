
void __fastcall FUN_005db0e6(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
  piVar5 = *(int **)(param_1 + 0x34);
  if (piVar5 != *(int **)(param_1 + 0x38)) {
    do {
      piVar1 = (int *)*piVar5;
      if ((((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x8c))(0x4000), cVar2 != '\0')
           ) && (cVar2 = FUN_005de012(), cVar2 != '\0')) &&
         ((cVar2 = (**(code **)(*piVar1 + 0x3c))(*(undefined4 *)(param_1 + 0x2c)), cVar2 != '\0' &&
          (iVar3 = (**(code **)(*piVar1 + 0x18))(), iVar3 != 0)))) {
        piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
        cVar2 = (**(code **)(*piVar4 + 0x8c))(0x4000);
        if (cVar2 == '\0') {
          (**(code **)(*piVar1 + 0xd4))(piVar1 + 3,1);
        }
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 != *(int **)(param_1 + 0x38));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
  return;
}

