
void __thiscall
FUN_004c3e5c(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 != 0) {
    cVar1 = *param_4;
    if (((cVar1 == param_4[2]) && (cVar1 == param_4[1])) && (cVar1 == param_4[3])) {
      *(int *)(*(int *)(param_1 + 8) + 8) = iVar2;
      piVar3 = *(int **)(param_1 + 8);
    }
    else {
      *(int *)(*(int *)(param_1 + 4) + 8) = iVar2;
      piVar3 = *(int **)(param_1 + 4);
    }
    (**(code **)(*piVar3 + 0x18))(param_2,param_3,param_4,param_5);
  }
  return;
}

