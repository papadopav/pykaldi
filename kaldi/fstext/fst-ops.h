#ifndef PYKALDI_FSTEXT_FST_OPS_H_
#define PYKALDI_FSTEXT_FST_OPS_H_ 1

#include "fst/fstlib.h"
#include "fstext/lattice-weight.h"

namespace fst {

typedef Fst<LogArc> LogFst;
typedef MutableFst<LogArc> LogMutableFst;
typedef ArcTpl<LatticeWeightTpl<float>> LatticeArc;
typedef Fst<LatticeArc> LatticeFst;
typedef MutableFst<LatticeArc> LatticeMutableFst;
typedef ArcTpl<CompactLatticeWeightTpl<LatticeWeightTpl<float>,int32>> CompactLatticeArc;
typedef Fst<CompactLatticeArc> CompactLatticeFst;
typedef MutableFst<CompactLatticeArc> CompactLatticeMutableFst;
typedef ArcTpl<LexicographicWeight<TropicalWeight,LexicographicWeight<TropicalWeight,TropicalWeight>>> KwsIndexArc;
typedef Fst<KwsIndexArc> KwsIndexFst;
typedef MutableFst<KwsIndexArc> KwsIndexMutableFst;

REGISTER_FST(VectorFst, LatticeArc);
REGISTER_FST(VectorFst, CompactLatticeArc);
REGISTER_FST(VectorFst, KwsIndexArc);
REGISTER_FST(ConstFst, LatticeArc);
REGISTER_FST(ConstFst, CompactLatticeArc);
REGISTER_FST(ConstFst, KwsIndexArc);

template<class Arc>
void FstToBytes(const Fst<Arc> &fst, string *result) {
  FstToString<Arc>(fst, result);
}

Fst<StdArc> *BytesToStdFst(const string &s) {
  return StringToFst<StdArc>(s);
}

Fst<LogArc> *BytesToLogFst(const string &s) {
  return StringToFst<LogArc>(s);
}

Fst<LatticeArc> *BytesToLatticeFst(const string &s) {
  return StringToFst<LatticeArc>(s);
}

Fst<CompactLatticeArc> *BytesToCompactLatticeFst(const string &s) {
  return StringToFst<CompactLatticeArc>(s);
}

Fst<KwsIndexArc> *BytesToKwsIndexFst(const string &s) {
  return StringToFst<KwsIndexArc>(s);
}

template <class Arc>
bool VerifyExt(const Fst<Arc> &fst) {
  return Verify(fst);
}

template <class Arc>
typename Arc::StateId CountStatesExt(const Fst<Arc> &fst) {
  return CountStates(fst);
}

template <class Arc>
typename Arc::StateId CountArcsExt(const Fst<Arc> &fst) {
  return CountArcs(fst);
}

template <class Arc>
void ArcSortExt(MutableFst<Arc> *fst, script::ArcSortType sort_type) {
  if (sort_type == script::ILABEL_SORT) {
    ILabelCompare<Arc> icomp;
    ArcSort(fst, icomp);
  } else{
    OLabelCompare<Arc> ocomp;
    ArcSort(fst, ocomp);
  }
}

template <class Arc>
void ClosureExt(MutableFst<Arc> *fst, ClosureType closure_type) {
  Closure(fst, closure_type);
}

template <class Arc>
void ConcatExt(MutableFst<Arc> *fst1, const Fst<Arc> &fst2) {
  Concat(fst1, fst2);
}

template <class Arc>
void ConnectExt(MutableFst<Arc> *fst) {
  Connect(fst);
}

template <class Arc>
void DecodeExt(MutableFst<Arc> *fst, const EncodeMapper<Arc> &mapper) {
  Decode(fst, mapper);
}

template <class Arc>
void EncodeExt(MutableFst<Arc> *fst, EncodeMapper<Arc> *mapper) {
  Encode(fst, mapper);
}

template <class Arc>
void InvertExt(MutableFst<Arc> *fst) {
  Invert(fst);
}

template <class Arc>
void MinimizeExt(MutableFst<Arc> *fst, MutableFst<Arc> *sfst = nullptr,
                 float delta = kDelta, bool allow_nondet = false) {
  Minimize(fst, sfst, delta, allow_nondet);
}

template <class Arc>
void ProjectExt(MutableFst<Arc> *fst, ProjectType project_type) {
  Project(fst, project_type);
}

template <class Arc>
void PruneExt(MutableFst<Arc> *fst, typename Arc::Weight weight_threshold,
              typename Arc::StateId state_threshold = kNoStateId,
              double delta = kDelta) {
  Prune(fst, weight_threshold, state_threshold, delta);
}

template <class Arc>
void PushExt(MutableFst<Arc> *fst, ReweightType type, float delta = kDelta,
             bool remove_total_weight = false) {
  Push(fst, type, delta, remove_total_weight);
}

template <class Arc>
void RelabelExt(
    MutableFst<Arc> *fst,
    const std::vector<std::pair<typename Arc::Label, typename Arc::Label>>
        &ipairs,
    const std::vector<std::pair<typename Arc::Label, typename Arc::Label>>
        &opairs) {
  Relabel(fst, ipairs, opairs);
}

template <class Arc>
void RelabelTables(
    MutableFst<Arc> *fst,
    const SymbolTable *old_isymbols, const SymbolTable *new_isymbols,
    const string &unknown_isymbol, bool attach_new_isymbols,
    const SymbolTable *old_osymbols, const SymbolTable *new_osymbols,
    const string &unknown_osymbol, bool attach_new_osymbols) {
  Relabel(fst, old_isymbols, new_isymbols, unknown_isymbol, attach_new_isymbols,
          old_osymbols, new_osymbols, unknown_osymbol, attach_new_osymbols);
}

template <class Arc>
void ReweightExt(MutableFst<Arc> *fst,
                 const std::vector<typename Arc::Weight> &potential,
                 ReweightType type) {
  Reweight(fst, potential, type);
}

template <class Arc>
void RmEpsilonExt(MutableFst<Arc> *fst, bool connect = true,
                  typename Arc::Weight weight_threshold = Arc::Weight::Zero(),
                  typename Arc::StateId state_threshold = kNoStateId,
                  float delta = kDelta) {
  RmEpsilon(fst, connect, weight_threshold, state_threshold, delta);
}

template <class Arc>
bool TopSortExt(MutableFst<Arc> *fst) {
  return TopSort(fst);
}

template <class Arc>
void UnionExt(MutableFst<Arc> *fst1, const Fst<Arc> &fst2) {
  Union(fst1, fst2);
}


template <class Arc>
void MapExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst, script::MapType map_type,
            float delta, const typename Arc::Weight &weight) {
  if (map_type == script::ARC_SUM_MAPPER) {
    return StateMap(ifst, ofst, ArcSumMapper<Arc>(ifst));
  } else if (map_type == script::ARC_UNIQUE_MAPPER) {
    return StateMap(ifst, ofst, ArcUniqueMapper<Arc>(ifst));
  } else if (map_type == script::IDENTITY_MAPPER) {
    return ArcMap(ifst, ofst, IdentityArcMapper<Arc>());
  } else if (map_type == script::INPUT_EPSILON_MAPPER) {
    return ArcMap(ifst, ofst, InputEpsilonMapper<Arc>());
  } else if (map_type == script::INVERT_MAPPER) {
    return ArcMap(ifst, ofst, InvertWeightMapper<Arc>());
  } else if (map_type == script::OUTPUT_EPSILON_MAPPER) {
    return ArcMap(ifst, ofst, OutputEpsilonMapper<Arc>());
  } else if (map_type == script::PLUS_MAPPER) {
    return ArcMap(ifst, ofst, PlusMapper<Arc>(weight));
  } else if (map_type == script::QUANTIZE_MAPPER) {
    return ArcMap(ifst, ofst, QuantizeMapper<Arc>(delta));
  } else if (map_type == script::RMWEIGHT_MAPPER) {
    return ArcMap(ifst, ofst, RmWeightMapper<Arc>());
  } else if (map_type == script::SUPERFINAL_MAPPER) {
    return ArcMap(ifst, ofst, SuperFinalMapper<Arc>());
  } else if (map_type == script::TIMES_MAPPER) {
    return ArcMap(ifst, ofst, TimesMapper<Arc>(weight));
  } else {
    FSTERROR() << "Unknown or unsupported mapper type: " << map_type;
    ofst->SetProperties(kError, kError);
  }
}

template <class Arc>
void ComposeExt(const Fst<Arc> &ifst1, const Fst<Arc> &ifst2,
                MutableFst<Arc> *ofst, bool connect,
                ComposeFilter compose_filter) {
  Compose(ifst1, ifst2, ofst, ComposeOptions(connect, compose_filter));
}

template <class Arc>
void DeterminizeExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst,
                    float delta = kDelta,
                    typename Arc::Weight weight_threshold = Arc::Weight::Zero(),
                    typename Arc::StateId state_threshold = kNoStateId,
                    typename Arc::Label subsequential_label = 0,
                    DeterminizeType type = DETERMINIZE_FUNCTIONAL,
                    bool increment_subsequential_label = false) {
  const DeterminizeOptions<Arc> opts(delta, weight_threshold, state_threshold,
                                     subsequential_label, type,
                                     increment_subsequential_label);
  Determinize(ifst, ofst, opts);
}

template <class Arc>
void DifferenceExt(const Fst<Arc> &ifst1, const Fst<Arc> &ifst2,
                   MutableFst<Arc> *ofst, bool connect,
                   ComposeFilter compose_filter) {
  Difference(ifst1, ifst2, ofst, ComposeOptions(connect, compose_filter));
}

template <class Arc>
void DisambiguateExt(
    const Fst<Arc> &ifst, MutableFst<Arc> *ofst, float delta = kDelta,
    typename Arc::Weight weight_threshold = Arc::Weight::Zero(),
    typename Arc::StateId state_threshold = kNoStateId,
    typename Arc::Label subsequential_label = 0) {
  const DisambiguateOptions<Arc> opts(delta, weight_threshold, state_threshold,
                                      subsequential_label);
  Disambiguate(ifst, ofst, opts);
}

template <class Arc>
void EpsNormalizeExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst,
                    EpsNormalizeType type = EPS_NORM_INPUT) {
  EpsNormalize<Arc, GALLIC>(ifst, ofst, type);
}

template <class Arc>
bool EqualExt(const Fst<Arc> &fst1, const Fst<Arc> &fst2,
              float delta = kDelta) {
  return Equal(fst1, fst2, delta);
}

template <class Arc>
bool EquivalentExt(const Fst<Arc> &fst1, const Fst<Arc> &fst2,
                   double delta, bool *error) {
  return Equivalent(fst1, fst2, delta, error);
}


template <class Arc>
void IntersectExt(const Fst<Arc> &ifst1, const Fst<Arc> &ifst2,
                  MutableFst<Arc> *ofst, bool connect,
                  ComposeFilter compose_filter) {
  Intersect(ifst1, ifst2, ofst, ComposeOptions(connect, compose_filter));
}

template <class Arc>
bool IsomorphicExt(const Fst<Arc> &fst1, const Fst<Arc> &fst2,
                   float delta = kDelta) {
  return Isomorphic(fst1, fst2, delta);
}

template <class Arc>
void PruneExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst,
              typename Arc::Weight weight_threshold,
              typename Arc::StateId state_threshold = kNoStateId,
              float delta = kDelta) {
  const PruneOptions<Arc, AnyArcFilter<Arc>> opts(
      weight_threshold, state_threshold, AnyArcFilter<Arc>(), nullptr, delta);
  Prune(ifst, ofst, opts);
}

template <class Arc>
void PushExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst, uint32 flags,
             ReweightType type, float delta) {
  if (type == REWEIGHT_TO_FINAL)
    Push<Arc, REWEIGHT_TO_FINAL>(ifst, ofst, flags, delta);
  else
    Push<Arc, REWEIGHT_TO_INITIAL>(ifst, ofst, flags, delta);
}

template <class Arc>
bool RandEquivalentExt(const Fst<Arc> &fst1, const Fst<Arc> &fst2,
                       int32 num_paths, float delta, time_t seed,
                       script::RandArcSelection selector_type,
                       int32 max_length, bool *error) {
  if (selector_type == script::UNIFORM_ARC_SELECTOR) {
    const UniformArcSelector<Arc> selector(seed);
    const RandGenOptions<UniformArcSelector<Arc>> ropts(selector, max_length);
    return RandEquivalent(fst1, fst2, num_paths, delta, ropts, error);
  } else if (selector_type == script::FAST_LOG_PROB_ARC_SELECTOR) {
    const FastLogProbArcSelector<Arc> selector(seed);
    const RandGenOptions<FastLogProbArcSelector<Arc>> ropts(selector,
                                                            max_length);
    return RandEquivalent(fst1, fst2, num_paths, delta, ropts, error);
  } else {
    const LogProbArcSelector<Arc> selector(seed);
    const RandGenOptions<LogProbArcSelector<Arc>> ropts(selector, max_length);
    return RandEquivalent(fst1, fst2, num_paths, delta, ropts, error);
  }
}

template <class Arc>
void RandGenExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst, time_t seed,
                script::RandArcSelection selector_type, int32 max_length,
                int32 num_paths, bool weighted, bool remove_total_weight) {
  if (selector_type == script::UNIFORM_ARC_SELECTOR) {
    const UniformArcSelector<Arc> selector(seed);
    const RandGenOptions<UniformArcSelector<Arc>> ropts(
        selector, max_length, num_paths, weighted, remove_total_weight);
    RandGen(ifst, ofst, ropts);
  } else if (selector_type == script::FAST_LOG_PROB_ARC_SELECTOR) {
    const FastLogProbArcSelector<Arc> selector(seed);
    const RandGenOptions<FastLogProbArcSelector<Arc>> ropts(
        selector, max_length, num_paths, weighted, remove_total_weight);
    RandGen(ifst, ofst, ropts);
  } else {
    const LogProbArcSelector<Arc> selector(seed);
    const RandGenOptions<LogProbArcSelector<Arc>> ropts(
        selector, max_length, num_paths, weighted, remove_total_weight);
    RandGen(ifst, ofst, ropts);
  }
}

// FIXME: Clif gets confused when this function is templated on the arc type.

void StdReplace(
    const std::vector<std::pair<typename StdArc::Label, StdFst *>> &pairs,
    StdMutableFst *ofst, int64 root_label, ReplaceLabelType call_label_type,
    ReplaceLabelType return_label_type, int64 return_label) {
  ReplaceFstOptions<StdArc> opts(root_label, call_label_type,
                                 return_label_type, return_label);
  using LabelFstPair = std::pair<typename StdArc::Label, const StdFst *>;
  using LabelFstPairVector = const std::vector<LabelFstPair>;
  // FIXME: This cast is needed because CLIF gets confused if the FST type
  // in the first argument is const.
  ReplaceFst<StdArc> rfst(reinterpret_cast<LabelFstPairVector&>(pairs), opts);
  // Checks for cyclic dependencies before attempting expansion.
  if (rfst.CyclicDependencies()) {
    FSTERROR() << "Replace: Cyclic dependencies detected; cannot expand";
    ofst->SetProperties(kError, kError);
    return;
  }
  opts.gc = true;     // Caching options to speed up batch copy.
  opts.gc_limit = 0;
  *ofst = rfst;
}

void LogReplace(
    const std::vector<std::pair<typename LogArc::Label, LogFst *>> &pairs,
    LogMutableFst *ofst, int64 root_label, ReplaceLabelType call_label_type,
    ReplaceLabelType return_label_type, int64 return_label) {
  ReplaceFstOptions<LogArc> opts(root_label, call_label_type,
                                 return_label_type, return_label);
  using LabelFstPair = std::pair<typename LogArc::Label, const LogFst *>;
  using LabelFstPairVector = const std::vector<LabelFstPair>;
  // FIXME: This cast is needed because CLIF gets confused if the FST type
  // in the first argument is const.
  ReplaceFst<LogArc> rfst(reinterpret_cast<LabelFstPairVector&>(pairs), opts);
  // Checks for cyclic dependencies before attempting expansion.
  if (rfst.CyclicDependencies()) {
    FSTERROR() << "Replace: Cyclic dependencies detected; cannot expand";
    ofst->SetProperties(kError, kError);
    return;
  }
  opts.gc = true;     // Caching options to speed up batch copy.
  opts.gc_limit = 0;
  *ofst = rfst;
}

void LatticeReplace(
    const std::vector<std::pair<typename LatticeArc::Label, LatticeFst *>> &pairs,
    LatticeMutableFst *ofst, int64 root_label, ReplaceLabelType call_label_type,
    ReplaceLabelType return_label_type, int64 return_label) {
  ReplaceFstOptions<LatticeArc> opts(root_label, call_label_type,
                                     return_label_type, return_label);
  using LabelFstPair = std::pair<typename LatticeArc::Label, const LatticeFst *>;
  using LabelFstPairVector = const std::vector<LabelFstPair>;
  // FIXME: This cast is needed because CLIF gets confused if the FST type
  // in the first argument is const.
  ReplaceFst<LatticeArc> rfst(reinterpret_cast<LabelFstPairVector&>(pairs), opts);
  // Checks for cyclic dependencies before attempting expansion.
  if (rfst.CyclicDependencies()) {
    FSTERROR() << "Replace: Cyclic dependencies detected; cannot expand";
    ofst->SetProperties(kError, kError);
    return;
  }
  opts.gc = true;     // Caching options to speed up batch copy.
  opts.gc_limit = 0;
  *ofst = rfst;
}

void CompactLatticeReplace(
    const std::vector<std::pair<typename CompactLatticeArc::Label, CompactLatticeFst *>> &pairs,
    CompactLatticeMutableFst *ofst, int64 root_label, ReplaceLabelType call_label_type,
    ReplaceLabelType return_label_type, int64 return_label) {
  ReplaceFstOptions<CompactLatticeArc> opts(root_label, call_label_type,
                                            return_label_type, return_label);
  using LabelFstPair = std::pair<typename CompactLatticeArc::Label, const CompactLatticeFst *>;
  using LabelFstPairVector = const std::vector<LabelFstPair>;
  // FIXME: This cast is needed because CLIF gets confused if the FST type
  // in the first argument is const.
  ReplaceFst<CompactLatticeArc> rfst(reinterpret_cast<LabelFstPairVector&>(pairs), opts);
  // Checks for cyclic dependencies before attempting expansion.
  if (rfst.CyclicDependencies()) {
    FSTERROR() << "Replace: Cyclic dependencies detected; cannot expand";
    ofst->SetProperties(kError, kError);
    return;
  }
  opts.gc = true;     // Caching options to speed up batch copy.
  opts.gc_limit = 0;
  *ofst = rfst;
}

void KwsIndexReplace(
    const std::vector<std::pair<typename KwsIndexArc::Label, KwsIndexFst *>> &pairs,
    KwsIndexMutableFst *ofst, int64 root_label, ReplaceLabelType call_label_type,
    ReplaceLabelType return_label_type, int64 return_label) {
  ReplaceFstOptions<KwsIndexArc> opts(root_label, call_label_type,
                                      return_label_type, return_label);
  using LabelFstPair = std::pair<typename KwsIndexArc::Label, const KwsIndexFst *>;
  using LabelFstPairVector = const std::vector<LabelFstPair>;
  // FIXME: This cast is needed because CLIF gets confused if the FST type
  // in the first argument is const.
  ReplaceFst<KwsIndexArc> rfst(reinterpret_cast<LabelFstPairVector&>(pairs), opts);
  // Checks for cyclic dependencies before attempting expansion.
  if (rfst.CyclicDependencies()) {
    FSTERROR() << "Replace: Cyclic dependencies detected; cannot expand";
    ofst->SetProperties(kError, kError);
    return;
  }
  opts.gc = true;     // Caching options to speed up batch copy.
  opts.gc_limit = 0;
  *ofst = rfst;
}

template <class Arc>
void ReverseExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst,
                bool require_superinitial=true) {
  Reverse(ifst, ofst, require_superinitial);
}

template <class Arc>
void RmEpsilonHelper(MutableFst<Arc> *fst,
                     std::vector<typename Arc::Weight> *distance,
                     QueueType queue_type, float delta, bool connect,
                     typename Arc::Weight weight_threshold,
                     typename Arc::StateId state_threshold) {
  using StateId = typename Arc::StateId;
  using Weight = typename Arc::Weight;
  switch (queue_type) {
    case AUTO_QUEUE: {
      AutoQueue<StateId> queue(*fst, distance, EpsilonArcFilter<Arc>());
      fst::RmEpsilonOptions<Arc, AutoQueue<StateId>> ropts(
          &queue, delta, connect, weight_threshold, state_threshold);
      RmEpsilon(fst, distance, ropts);
      break;
    }
    case FIFO_QUEUE: {
      FifoQueue<StateId> queue;
      fst::RmEpsilonOptions<Arc, FifoQueue<StateId>> ropts(
          &queue, delta, connect, weight_threshold, state_threshold);
      RmEpsilon(fst, distance, ropts);
      break;
    }
    case LIFO_QUEUE: {
      LifoQueue<StateId> queue;
      fst::RmEpsilonOptions<Arc, LifoQueue<StateId>> ropts(
          &queue, delta, connect, weight_threshold, state_threshold);
      RmEpsilon(fst, distance, ropts);
      break;
    }
    case SHORTEST_FIRST_QUEUE: {
      NaturalShortestFirstQueue<StateId, Weight> queue(*distance);
      fst::RmEpsilonOptions<Arc, NaturalShortestFirstQueue<StateId, Weight>>
          ropts(&queue, delta, connect, weight_threshold, state_threshold);
      RmEpsilon(fst, distance, ropts);
      break;
    }
    case STATE_ORDER_QUEUE: {
      StateOrderQueue<StateId> queue;
      fst::RmEpsilonOptions<Arc, StateOrderQueue<StateId>> ropts(
          &queue, delta, connect, weight_threshold, state_threshold);
      RmEpsilon(fst, distance, ropts);
      break;
    }
    case TOP_ORDER_QUEUE: {
      TopOrderQueue<StateId> queue(*fst, EpsilonArcFilter<Arc>());
      fst::RmEpsilonOptions<Arc, TopOrderQueue<StateId>> ropts(
          &queue, delta, connect, weight_threshold, state_threshold);
      RmEpsilon(fst, distance, ropts);
      break;
    }
    default:
      FSTERROR() << "Unknown queue type: " << queue_type;
      fst->SetProperties(kError, kError);
  }
}

template <class Arc>
void RmEpsilonExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst,
                  bool connect = true,bool reverse = false,
                  QueueType queue_type = AUTO_QUEUE, float delta = kDelta,
                  typename Arc::Weight weight_threshold = Arc::Weight::Zero(),
                  typename Arc::StateId state_threshold = kNoStateId) {
  std::vector<typename Arc::Weight> distance;
  if (reverse) {
    VectorFst<Arc> rfst;
    Reverse(ifst, &rfst, false);
    RmEpsilonHelper(&rfst, &distance, queue_type, delta, connect,
                    weight_threshold, state_threshold);
    Reverse(rfst, ofst, false);
    if (rfst.NumStates() != ofst->NumStates())
      RmEpsilonHelper(ofst, &distance, queue_type, delta, connect,
                      weight_threshold, state_threshold);
  } else {
    *ofst = ifst;
    RmEpsilonHelper(ofst, &distance, queue_type, delta, connect,
                    weight_threshold, state_threshold);
  }
}

template <class Arc>
std::vector<typename Arc::Weight> *ShortestDistanceExt(
    const Fst<Arc> &fst, bool reverse = false,
    typename Arc::StateId source = kNoStateId,
    QueueType queue_type = AUTO_QUEUE, float delta = kDelta) {
  using StateId = typename Arc::StateId;
  using Weight = typename Arc::Weight;
  using ArcFilter = AnyArcFilter<Arc>;
  std::vector<Weight> *distance = new std::vector<Weight>();
  if (reverse) {
    // Only the simpler signature supports shortest distance to final states;
    // `source` and `queue_type` arguments are ignored.
    ShortestDistance(fst, distance, true, delta);
    return distance;
  }
  switch (queue_type) {
    case AUTO_QUEUE: {
      using Queue = AutoQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue(fst, distance, ArcFilter()));
      ShortestDistanceOptions<Arc, Queue, ArcFilter> sdopts(
          queue.get(), ArcFilter(), source, delta);
      ShortestDistance(fst, distance, sdopts);
      return distance;
    }
    case FIFO_QUEUE: {
      using Queue = FifoQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue());
      ShortestDistanceOptions<Arc, Queue, ArcFilter> sdopts(
          queue.get(), ArcFilter(), source, delta);
      ShortestDistance(fst, distance, sdopts);
      return distance;
    }
    case LIFO_QUEUE: {
      using Queue = LifoQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue());
      ShortestDistanceOptions<Arc, Queue, ArcFilter> sdopts(
          queue.get(), ArcFilter(), source, delta);
      ShortestDistance(fst, distance, sdopts);
      return distance;
    }
    case SHORTEST_FIRST_QUEUE: {
      using Queue = NaturalShortestFirstQueue<StateId, Weight>;
      std::unique_ptr<Queue> queue(new Queue(*distance));
      ShortestDistanceOptions<Arc, Queue, ArcFilter> sdopts(
          queue.get(), ArcFilter(), source, delta);
      ShortestDistance(fst, distance, sdopts);
      return distance;
    }
    case STATE_ORDER_QUEUE: {
      using Queue = StateOrderQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue());
      ShortestDistanceOptions<Arc, Queue, ArcFilter> sdopts(
          queue.get(), ArcFilter(), source, delta);
      ShortestDistance(fst, distance, sdopts);
      return distance;
    }
    case TOP_ORDER_QUEUE: {
      using Queue = TopOrderQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue(fst, ArcFilter()));
      ShortestDistanceOptions<Arc, Queue, ArcFilter> sdopts(
          queue.get(), ArcFilter(), source, delta);
      ShortestDistance(fst, distance, sdopts);
      return distance;
    }
    default:
      FSTERROR() << "Unknown queue type: " << queue_type;
      return distance;
  }
}

template <class Arc>
void ShortestPathExt(
    const Fst<Arc> &ifst, MutableFst<Arc> *ofst,
    const int32 nshortest = 1, const bool unique = false,
    QueueType queue_type = AUTO_QUEUE, float delta = kDelta,
    typename Arc::Weight weight_threshold = Arc::Weight::Zero(),
    typename Arc::StateId state_threshold = kNoStateId) {
  using StateId = typename Arc::StateId;
  using Weight = typename Arc::Weight;
  using ArcFilter = AnyArcFilter<Arc>;
  std::vector<Weight> distance;
  switch (queue_type) {
    case AUTO_QUEUE: {
      using Queue = AutoQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue(ifst, &distance, ArcFilter()));
      fst::ShortestPathOptions<Arc, Queue, ArcFilter> spopts(
          queue.get(), ArcFilter(), nshortest, unique, false, delta,
          false, weight_threshold, state_threshold);
      ShortestPath(ifst, ofst, &distance, spopts);
      return;
    }
    case FIFO_QUEUE: {
      using Queue = FifoQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue());
      fst::ShortestPathOptions<Arc, Queue, ArcFilter> spopts(
          queue.get(), ArcFilter(), nshortest, unique, false, delta,
          false, weight_threshold, state_threshold);
      ShortestPath(ifst, ofst, &distance, spopts);
      return;
    }
    case LIFO_QUEUE: {
      using Queue = LifoQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue());
      fst::ShortestPathOptions<Arc, Queue, ArcFilter> spopts(
          queue.get(), ArcFilter(), nshortest, unique, false, delta,
          false, weight_threshold, state_threshold);
      ShortestPath(ifst, ofst, &distance, spopts);
      return;
    }
    case SHORTEST_FIRST_QUEUE: {
      using Queue = NaturalShortestFirstQueue<StateId, Weight>;
      std::unique_ptr<Queue> queue(new Queue(distance));
      fst::ShortestPathOptions<Arc, Queue, ArcFilter> spopts(
          queue.get(), ArcFilter(), nshortest, unique, false, delta,
          false, weight_threshold, state_threshold);
      ShortestPath(ifst, ofst, &distance, spopts);
      return;
    }
    case STATE_ORDER_QUEUE: {
      using Queue = StateOrderQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue());
      fst::ShortestPathOptions<Arc, Queue, ArcFilter> spopts(
          queue.get(), ArcFilter(), nshortest, unique, false, delta,
          false, weight_threshold, state_threshold);
      ShortestPath(ifst, ofst, &distance, spopts);
      return;
    }
    case TOP_ORDER_QUEUE: {
      using Queue = TopOrderQueue<StateId>;
      std::unique_ptr<Queue> queue(new Queue(ifst, ArcFilter()));
      fst::ShortestPathOptions<Arc, Queue, ArcFilter> spopts(
          queue.get(), ArcFilter(), nshortest, unique, false, delta,
          false, weight_threshold, state_threshold);
      ShortestPath(ifst, ofst, &distance, spopts);
      return;
    }
    default:
      FSTERROR() << "Unknown queue type: " << queue_type;
      ofst->SetProperties(kError, kError);
  }
}

template <class Arc>
void SynchronizeExt(const Fst<Arc> &ifst, MutableFst<Arc> *ofst) {
  Synchronize(ifst, ofst);
}

}  // namespace fst

#endif  // PYKALDI_FSTEXT_FST_OPS_H_
