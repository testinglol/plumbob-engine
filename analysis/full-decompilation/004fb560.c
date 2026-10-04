
void __fastcall FUN_004fb560(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (*(int **)(param_1 + 0x128) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x128) + 0x24))();
    if (cVar2 != '\0') {
      iVar1 = **(int **)(param_1 + 0x128);
      uVar3 = (**(code **)(iVar1 + 0x74))(0,10000,1,1);
      (**(code **)(iVar1 + 0x7c))(uVar3);
    }
    *(undefined4 *)(param_1 + 0x128) = 0;
  }
  return;
}

