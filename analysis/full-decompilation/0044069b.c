
void __fastcall FUN_0044069b(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_c;
  int *local_8;
  
  if (*(char *)(param_1 + 0x10) != '\0') {
    *(undefined1 *)(param_1 + 0x11) = 0;
    FUN_00446175();
    for (local_8 = *(int **)(param_1 + 0x18); local_8 != *(int **)(param_1 + 0x1c);
        local_8 = local_8 + 1) {
      if (*local_8 != 0) {
        piVar1 = (int *)*local_8;
        FUN_0044387c(piVar1);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x10))(1);
        }
      }
    }
    for (local_c = *(int **)(param_1 + 100); local_c != *(int **)(param_1 + 0x68);
        local_c = local_c + 1) {
      iVar2 = *local_c;
      if (iVar2 != 0) {
        FUN_00435f6d();
        FUN_006321f0(iVar2);
      }
    }
    FUN_00448aa5(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x68));
    iVar2 = *(int *)(*(int *)(param_1 + 0x70) + 8);
    while (iVar2 != *(int *)(param_1 + 0x70)) {
      iVar3 = *(int *)(iVar2 + 0x14);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        FUN_00448427();
        FUN_006321f0(iVar3);
      }
      FUN_0041674f(iVar3);
    }
    FUN_00448a16();
    FUN_00448aa5(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
    FUN_004071be(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

