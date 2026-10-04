
void __thiscall
FUN_004c9b93(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  float10 fVar2;
  
  if (param_6 == 0) {
    FUN_004734bd((float)param_3,(float)param_3,1,DAT_006e5490);
    FUN_004734bd((float)param_5,(float)param_5,1,DAT_006e5490);
  }
  else {
    if (*(int *)(param_1 + 0x24) == 0) {
      FUN_00636264((double)(param_2 - param_3) * (double)(param_2 - param_3) +
                   (double)(param_4 - param_5) * (double)(param_4 - param_5));
      iVar1 = __ftol();
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x2c);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x28);
      fVar2 = (float10)FUN_00636264((double)(param_3 - param_2) * (double)(param_3 - param_2) +
                                    (double)(param_5 - param_4) * (double)(param_5 - param_4));
      *(float *)(param_1 + 0x30) = (float)(fVar2 / (float10)iVar1);
    }
    FUN_004734bd((float)param_2,(float)param_3,iVar1,DAT_006e5490);
    FUN_004734bd((float)param_4,(float)param_5,iVar1,DAT_006e5490);
  }
  *(undefined4 *)(param_1 + 0x20) = 1;
  return;
}

