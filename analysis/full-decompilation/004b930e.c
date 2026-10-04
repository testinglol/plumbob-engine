
void FUN_004b930e(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 local_408 [1024];
  int local_8;
  
  iVar2 = FUN_00635845(param_1,&DAT_006c7590);
  if (iVar2 != 0) {
    local_8 = iVar2;
    sVar1 = FUN_004b93e5(iVar2,&param_1);
    if (sVar1 == 0) {
      param_1 = 0x100;
      iVar5 = 0;
      iVar2 = param_2 + 2;
      do {
        FUN_0063711e(iVar2 + -2,1,1,local_8);
        FUN_0063711e(iVar2 + -1,1,1,local_8);
        FUN_0063711e(iVar2,1,1,local_8);
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar5 < param_1);
    }
    else {
      FUN_0063711e(local_408,4,param_1,iVar2);
      if (0 < param_1) {
        puVar4 = local_408;
        puVar3 = (undefined1 *)(param_2 + 2);
        iVar2 = param_1;
        do {
          puVar3[-2] = puVar3[(int)(local_408 + -param_2)];
          puVar3[-1] = puVar4[1];
          *puVar3 = *puVar4;
          puVar4 = puVar4 + 4;
          puVar3 = puVar3 + 4;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    FUN_0063558d(local_8);
  }
  return;
}

