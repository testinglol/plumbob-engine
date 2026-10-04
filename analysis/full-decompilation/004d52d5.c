
void __fastcall FUN_004d52d5(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 4) == 1) {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x44) = 0;
    *(undefined1 *)(param_1 + 0x45) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    local_c = param_1;
    local_8 = param_1;
    FUN_004b0542();
    FUN_004d2851();
    uVar4 = 0;
    uVar2 = 0;
    (**(code **)(*DAT_006fe8bc + 0x18))(0,0);
    FUN_005dadbc(uVar2,uVar4);
    piVar5 = &local_8;
    piVar3 = &local_c;
    (**(code **)(*DAT_006fe8bc + 0x18))(piVar3,piVar5);
    FUN_005d9928(piVar3,piVar5);
    iVar1 = local_c;
    iVar6 = local_8;
    (**(code **)(*DAT_006fe8bc + 0x18))(local_c,local_8);
    iVar1 = FUN_005da3e9(iVar1,iVar6);
    if (iVar1 != 0) {
      FUN_005ddddb();
    }
  }
  return;
}

