
void __fastcall FUN_005da2bc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int **)(param_1 + 0x18c) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x18c) + 0x184))();
    if (iVar2 == 0) {
      iVar1 = **(int **)(param_1 + 0x18c);
      uVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x180))();
      (**(code **)(iVar1 + 0x188))(uVar3);
      (**(code **)(**(int **)(param_1 + 0x18c) + 0x198))();
    }
    (**(code **)(**(int **)(param_1 + 0x18c) + 0x178))(0);
    if (iVar2 != 0) {
      iVar2 = **(int **)(param_1 + 0x18c);
      uVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x180))(*(int **)(param_1 + 0x18c) + 0x1f);
      (**(code **)(iVar2 + 0xd0))(uVar3);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x18c) + 0x188))(0);
    }
    (**(code **)(**(int **)(param_1 + 0x18c) + 0x168))();
    *(undefined1 *)(param_1 + 0x1a1) = 1;
    if (*(int *)(param_1 + 0x178) == 2) {
      (**(code **)(**(int **)(param_1 + 0x18c) + 0x60))
                (*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x194),
                 *(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x19c));
    }
  }
  return;
}

