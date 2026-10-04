
void __thiscall FUN_004316cf(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  size_t sVar6;
  undefined4 *puVar7;
  char local_204 [512];
  
  piVar2 = param_2;
  puVar3 = DAT_006e4a64;
  puVar7 = &DAT_006e4a64;
  do {
    puVar4 = puVar3;
    if (puVar4 == (undefined4 *)0x0) {
LAB_004316f9:
      piVar1 = param_1 + 4;
      if (param_2 != piVar1) {
        FUN_00431779(*param_2,param_2[1]);
      }
      param_2 = (int *)0x0;
      do {
        if (param_1[5] != *piVar1) {
          iVar5 = FUN_004316a5(piVar1);
          if (iVar5 == 0) {
            *param_1 = DAT_006e4a64;
            DAT_006e4a64 = param_1;
            return;
          }
        }
        FUN_00635858(local_204,&DAT_006c291c,*piVar2,param_2);
        sVar6 = _strlen(local_204);
        FUN_00431779(local_204,local_204 + sVar6);
        param_2 = (int *)((int)param_2 + 1);
      } while( true );
    }
    if (puVar4 == param_1) {
      *puVar7 = *param_1;
      goto LAB_004316f9;
    }
    puVar3 = (undefined4 *)*puVar4;
    puVar7 = puVar4;
  } while( true );
}

