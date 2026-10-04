
undefined4 __thiscall FUN_004e495b(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar2 = FUN_00635845(*(undefined4 *)(param_2 + 4),&DAT_006c0a78);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    FUN_006357d8(iVar2,s_Sims_object_dialogs__Do_not_edit_006c9bcc);
    FUN_006357d8(iVar2,s_Index_File_Message_Desc_Tree_ID_N_006c9b9c);
    piVar4 = (int *)*param_1;
    if (piVar4 != (int *)param_1[1]) {
      do {
        puVar1 = (undefined4 *)*piVar4;
        FUN_006357d8(iVar2,s__03d__s__s__s__d__d_006c9b84,*puVar1,puVar1[3],puVar1[0x15],
                     puVar1[0x18],(int)*(short *)(puVar1 + 1),(int)*(short *)((int)puVar1 + 6));
        param_2 = 0;
        do {
          FUN_006357d8(iVar2,&DAT_006c9b80,*(undefined1 *)(param_2 + 0x6c + (int)puVar1));
          param_2 = param_2 + 1;
        } while (param_2 < 8);
        FUN_006357d8(iVar2,&DAT_006c08dc);
        piVar4 = piVar4 + 1;
      } while (piVar4 != (int *)param_1[1]);
    }
    FUN_0063558d(iVar2);
    uVar3 = 1;
  }
  return uVar3;
}

