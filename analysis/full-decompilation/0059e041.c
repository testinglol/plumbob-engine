
int FUN_0059e041(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  if (*(int *)(param_4 + 0x1c) == 0) {
    iVar1 = FUN_0059e1b5(*(undefined4 *)(param_2 + 0x10),param_4 + 0x10);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_00473577(param_4);
    FUN_00594d67(iVar1);
  }
  iVar1 = FUN_00599e94(param_1,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_2 + 0x14) == 0) {
    FUN_005d3d38(*(undefined4 *)(iVar1 + 0xc));
  }
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
  *(undefined4 *)(param_1 + 0x98) = 1;
  return iVar1;
}

