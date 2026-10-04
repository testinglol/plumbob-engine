
void __fastcall FUN_005edeab(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    piVar3 = param_1 + 0x36;
    iVar2 = 4;
    do {
      if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((int *)param_1[0x75] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x75] + 0x18))();
      param_1[0x75] = 0;
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x4e));
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6f));
    FUN_005dddc1();
  }
  FUN_005dbf4d();
  return;
}

