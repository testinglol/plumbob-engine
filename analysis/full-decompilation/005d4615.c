
void __fastcall FUN_005d4615(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_005d0135();
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,(undefined4 *)(param_1 + 0x58),0);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x8c) != 0) {
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc);
    }
    piVar1 = *(int **)(param_1 + 0x58);
    (**(code **)(*piVar1 + 0xc))(piVar1,param_1 + 4);
  }
  return;
}

