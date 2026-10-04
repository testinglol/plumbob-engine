
int FUN_00476b41(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) &&
     (piVar2 = (int *)**(int **)(param_1 + 0x38), piVar2 != *(int **)(param_1 + 0x38))) {
    do {
      iVar1 = FUN_006359f2(piVar2[2],0,&cTSWin::RTTI_Type_Descriptor,
                           &cWinRelationship::RTTI_Type_Descriptor,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_00476b41(piVar2[2],param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x38));
  }
  return 0;
}

