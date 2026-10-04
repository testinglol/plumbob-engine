
void FUN_0051eb1f(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar1 = *param_3;
  iVar2 = param_3[1];
  iVar3 = *param_4;
  iVar4 = param_4[1];
  iVar5 = *(int *)(&DAT_006f2a74)[param_5];
  uVar6 = FUN_005d49d6(0,0,0);
  uVar6 = FUN_004096c2(uVar6);
  (**(code **)(iVar5 + 0x78))(param_2,iVar1 + iVar3,iVar2 + iVar4,uVar6);
  return;
}

