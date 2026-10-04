
undefined1 __fastcall FUN_0057f88e(int *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 unaff_retaddr;
  char *pcVar4;
  
  piVar1 = (int *)param_1[0x74];
  if (piVar1 == (int *)0x0) {
    pcVar4 = s_Attempt_to_play_note_with_no_cha_006d01c4;
  }
  else {
    if (param_1[0x2f] != 0) {
      iVar3 = (**(code **)(*param_1 + 0x88))(0x26);
      if (iVar3 != 0) {
        (**(code **)(*piVar1 + 0x84))(0x26,1,0);
      }
      uVar2 = (**(code **)(*piVar1 + 0x94))(unaff_retaddr);
      iVar3 = (**(code **)(*(int *)param_1[0x2f] + 0x88))(0x26);
      if (iVar3 != 0) {
        FUN_0057fa52();
        FUN_0057fa16();
      }
      return uVar2;
    }
    pcVar4 = s_Attempt_to_play_note_with_no_pat_006d01a0;
  }
  (**(code **)(DAT_006f6a78 + 200))(param_1,pcVar4);
  return 0;
}

