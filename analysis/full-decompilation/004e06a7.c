
void FUN_004e06a7(undefined4 param_1)

{
  char cVar1;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004e066d(param_1,s_Memory_Info__006c91b4);
  cVar1 = FUN_004e076c(local_2c);
  if (cVar1 != '\0') {
    FUN_004e066d(param_1,s_PageFaultCount___12d_006c919c,local_28);
    FUN_004e066d(param_1,s_PeakWorkingSetSize___12d_006c9180,local_24);
    FUN_004e066d(param_1,s_WorkingSetSize___12d_006c9168,local_20);
    FUN_004e066d(param_1,s_QuotaPeakPagedPoolUsage___12d_006c9144,local_1c);
    FUN_004e066d(param_1,s_QuotaPagedPoolUsage___12d_006c9124,local_18);
    FUN_004e066d(param_1,s_QuotaPeakNonPagedPoolUsage___12d_006c9100,local_14);
    FUN_004e066d(param_1,s_QuotaNonPagedPoolUsage___12d_006c90e0,local_10);
    FUN_004e066d(param_1,s_PagefileUsage___12d_006c90c8,local_c);
    FUN_004e066d(param_1,s_PeakPagefileUsage___12d_006c90a8,local_8);
  }
  return;
}

